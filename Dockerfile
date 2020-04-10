ARG ALPINE_VERSION=3.11

FROM alpine:${ALPINE_VERSION} as BASE

LABEL maintainer="Lucca Pessoa da Silva Matos - luccapsm@gmail.com" \
        org.label-schema.version="1.0.0" \
        org.label-schema.release-data="2020-04-09" \
        org.label-schema.url="https://github.com/lpmatos" \
        org.label-schema.alpine="https://alpinelinux.org/" \
        org.label-schema.gcc="https://gcc.gnu.org/" \
        org.label-schema.name="Linux Keylogger"

FROM BASE AS COMPILE

WORKDIR /tmp/compile

RUN set -ex && \
    apk update && \
    apk add --no-cache --update build-base gcc

COPY [ "./code", "." ]

RUN gcc -o keylogger keylogger.c

FROM BASE

ENV HOME=/usr/src/code

RUN apk add --no-cache --update gcc

WORKDIR ${HOME}

COPY --from=COMPILE [ "/tmp/compile/keylogger", "." ]

RUN find ./ -iname "*.o" -type f -exec chmod a+x {} \; -exec echo {} \;;

ENTRYPOINT []

CMD []