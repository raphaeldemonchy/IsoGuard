from flask import Flask, jsonify, request
from vm_manager import VMManager

app = Flask(__name__)
manager = VMManager()

@app.route('/vms', methods=['GET'])
def list_vms():
    return jsonify(manager.list_vms())

@app.route('/vms', methods=['POST'])
def create_vm():
    data = request.json
    manager.create_vm(data['name'], data['memory'], data['vcpu'], data['disk'], data['iso'])
    return jsonify({"status": "VM created"}), 201

@app.route('/vms/<name>', methods=['DELETE'])
def stop_vm(name):
    manager.stop_vm(name)
    return jsonify({"status": f"VM {name} stopped"})
