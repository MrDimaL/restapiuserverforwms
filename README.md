# Warehouse Management System API

## Описание задания

В рамках лабораторной работы необходимо разработать и реализовать **REST API** сервис для системы управления складом с использованием современных подходов к проектированию веб-сервисов.

Задачи работы:

1. Спроектировать REST API для выбранного варианта системы ([ZOHO](https://www.zoho.com/inventory/)).
2. Реализовать REST API сервис.
3. Реализовать аутентификацию.
4. Выполнить документирование API.
5. Провести тестирование.
6. Представить результат в виде **REST API сервиса**, документации, OpeAPI спецификацией и средством запуска **Docker**.

[Скачать файл с исходным заданием](system_design_task_02.pdf)

Система предназначена для:
- управления пользователями
- управления товарами
- учета складских остатков
- регистрации поступлений товаров
- списания товаров

Используемые технологии:
- Python 3.11
- FastAPI
- Uvicorn
- JWT (python-jose)
- Docker
- OpenAPI / Swagger

## Архитектура API

API реализовано в соответствии с REST-принципами:
- ресурсы представлены через URL
- используются HTTP методы (GET, POST, PATCH, DELETE)
- используются корректные HTTP статус-коды

---

## Запуск проекта
Локальный запуск

```bash
pip install -r requirements.txt
uvicorn app.main:app --reload
```

Запуск через Docker

```bash
docker-compose up --build
```

## Документация API

После запуска API доступен Swagger UI: http://localhost:8000/docs

Также в проекте присутствует файл: [OpenAPI](openapi.yaml)

## Аутентификация
В системе реализована JWT-аутентификация.

**Регистрация**

POST /auth/register

Пример:
```json
{
  "username": "admin",
  "password": "123"
}
```
**Авторизация**

POST /auth/login

Ответ:
```json
{
  "access_token": "jwt_token"
}
```
**Использование токена**
1. Нажать кнопку Authorize в Swagger
2. Ввести:
    ```Bearer <token>```

## Описание API
**Пользователи**
```
GET /users/{username} - получение пользователя
```
**Товары**
```
GET /products - список товаров
POST /products - создание товара
PATCH /products/{id} - обновление товара
DELETE /products/{id} - удаление товара
GET /products/search - поиск товаров
```
**Остатки**
```
GET /inventory - получение остатков
POST /inventory/writeoff - списание товара
```
**Поступления**
```
GET /arrivals - история поступлений
POST /arrivals - создание поступления
```
## Тестирование API

Тестирование выполняется через Swagger UI.

Основной сценарий:
1. Зарегистрировать пользователя
2. Выполнить вход
3. Скопировать access_token
4. Нажать Authorize
5. Вставить токен
6. Создать товар
7. Добавить поступление
8. Проверить остатки

## Тестирование ошибок
- Неверный логин -> 401 Unauthorized
- Недостаточно товара -> 400 Bad Request
- Несуществующий ресурс -> 404 Not Found

## Структура проекта
```
app/
|-- auth.py
|-- main.py
|-- schemas.py
|-- storage.py

docker-compose.yaml
Dockerfile
openapi.yaml
README.md
requirements.txt
system_design_task_02.pdf
```
## Docker
Для запуска:
```bash
docker-compose up --build
```

## Вывод

В рамках работы был реализован REST API сервис системы управления складом.

Реализовано:
- REST API endpoints
- JWT-аутентификация
- CRUD операции
- обработка ошибок
- Swagger документация
- OpenAPI спецификация
- Docker контейнеризация