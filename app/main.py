from fastapi import FastAPI, HTTPException, Depends
from app.schemas import *
from app.storage import *
from app.auth import *

app = FastAPI()

@app.post("/auth/register")
def register(user: UserCreate):
    users.append(user)
    return {"message": "User created"}

@app.post("/auth/login")
def login(user: UserCreate):
    for u in users:
        if u.username == user.username and u.password == user.password:
            token = create_token(user.username)
            return {"access_token": token}
    raise HTTPException(401, "Invalid credentials")

@app.get("/users/{username}")
def get_user(username: str):
    for u in users:
        if u.username == username:
            return u
    raise HTTPException(404, "User not found")

@app.post("/products")
def create_product(product: ProductCreate, user=Depends(get_current_user)):
    product_id = len(products) + 1
    products.append({"id": product_id, **product.dict()})
    inventory[product_id] = 0
    return products[-1]

@app.get("/products")
def get_products():
    return products

@app.get("/products/search")
def search_products(name: str):
    return [p for p in products if name.lower() in p["name"].lower()]

@app.get("/inventory")
def get_inventory():
    return inventory

@app.post("/inventory/writeoff")
def writeoff(product_id: int, quantity: int):
    if inventory.get(product_id, 0) < quantity:
        raise HTTPException(400, "Not enough stock")
    inventory[product_id] -= quantity
    return {"message": "Written off"}

@app.post("/arrivals")
def create_arrival(arrival: ArrivalCreate):
    if arrival.product_id not in inventory:
        raise HTTPException(404, "Product not found")

    inventory[arrival.product_id] += arrival.quantity
    arrivals.append(arrival.dict())
    return {"message": "Arrival added"}

@app.get("/arrivals")
def get_arrivals():
    return arrivals

@app.patch("/products/{product_id}")
def update_product(product_id: int, product: ProductCreate):
    for p in products:
        if p["id"] == product_id:
            p.update(product.dict())
            return p
    raise HTTPException(404, "Product not found")

@app.delete("/products/{product_id}")
def delete_product(product_id: int):
    for p in products:
        if p["id"] == product_id:
            products.remove(p)
            inventory.pop(product_id, None)
            return {"message": "Deleted"}
    raise HTTPException(404, "Product not found")