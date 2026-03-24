from fastapi import HTTPException, Depends
from fastapi.security import HTTPBearer
from jose import jwt

SECRET = "secret"

security = HTTPBearer()

def create_token(username):
    return jwt.encode({"sub": username}, SECRET, algorithm="HS256")

def get_current_user(token=Depends(security)):
    try:
        payload = jwt.decode(token.credentials, SECRET, algorithms=["HS256"])
        return payload["sub"]
    except:
        raise HTTPException(status_code=401, detail="Invalid token")