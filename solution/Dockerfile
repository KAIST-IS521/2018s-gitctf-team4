FROM debian:latest

# =========Install your package=========
RUN apt-get update && apt-get install -y \
      make \
      gcc  \
      python
# ======================================

# ======================================
# Build your exploit here
# ======================================


# ======Build and run your exploit=====
COPY exploit /bin/
# ======================================
