ARG ALPINE_VERSION=3.11

FROM alpine:${ALPINE_VERSION} as BASE

LABEL maintainer="Lucca Pessoa da Silva Matos - luccapsm@gmail.com" \
        org.label-schema.version="1.0.1" \
        org.label-schema.release-data="15-04-2020" \
        org.label-schema.url="https://github.com/lpmatos/simple-keylogger" \
        org.label-schema.alpine="https://alpinelinux.org/" \
        org.label-schema.gcc="https://gcc.gnu.org/" \
        org.label-schema.name="Linux Keylogger"

FROM BASE

ENV HOME=/usr/src/code

RUN set -ex && \
    apk update && \
    apk add --no-cache --update \
      gcc=9.2.0-r4 \
      musl-dev=1.1.24-r2

RUN apk add --no-cache --update \
      figlet=2.2.5-r0 \
      bash=5.0.11-r1

WORKDIR ${HOME}

COPY [ "./src", "." ]
