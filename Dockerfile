FROM cmakelib/build-linux:latest-debian-buster

RUN sed -i "s@http://\(deb\|security\).debian.org@https://mirrors.aliyun.com@g" /etc/apt/sources.list

RUN apt update

RUN apt install -y make g++

COPY . /app/icecode

WORKDIR /app/icecode

RUN cmake -B build -S .

RUN cmake --build build
