FROM python:3.9-slim

# Installer les dépendances nécessaires pour Libvirt
RUN apt-get update && apt-get install -y \
    qemu-kvm libvirt-daemon libvirt-clients \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app
RUN pip install -r requirements.txt

EXPOSE 5000
CMD ["python", "app/api.py"]
