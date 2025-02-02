FROM nginx:latest

WORKDIR /home/

COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./server .
COPY ./run.sh .

RUN apt-get update && apt-get install -y gcc libfcgi-dev spawn-fcgi \
    && rm -rf /var/lib/apt/lists/* \
    && chmod +x run.sh \
    && groupadd -g 101 nginx || true \
    && useradd -r -u 101 -g nginx nginx || true \
    && mkdir -p /var/run/nginx \
    && chown -R nginx:nginx /var/run/nginx

CMD ["./run.sh"]
