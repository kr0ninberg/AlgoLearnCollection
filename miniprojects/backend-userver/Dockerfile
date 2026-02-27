FROM userver:latest AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake

WORKDIR /app

COPY --chown=root:root app/ .

RUN cmake -S . -B build \
    && cmake --build build --config Release

FROM userver:latest

RUN apt-get update && apt-get install -y \
    libstdc++6

WORKDIR /app

EXPOSE 8080

COPY --from=builder /app/build/hello_service .

CMD ["./hello_service"]