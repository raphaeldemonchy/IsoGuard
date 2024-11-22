import libvirt
import os

class VMManager:
    def __init__(self):
        self.conn = libvirt.open("qemu:///system")
        if self.conn is None:
            raise Exception("Failed to connect to QEMU/KVM hypervisor.")

    def create_vm(self, name, memory, vcpu, disk_path, iso_path):
        xml_config = f"""
        <domain type='kvm'>
          <name>{name}</name>
          <memory unit='MiB'>{memory}</memory>
          <vcpu>{vcpu}</vcpu>
          <os>
            <type arch='x86_64'>hvm</type>
            <boot dev='cdrom'/>
          </os>
          <devices>
            <disk type='file' device='disk'>
              <driver name='qemu' type='qcow2'/>
              <source file='{disk_path}'/>
              <target dev='vda' bus='virtio'/>
            </disk>
            <disk type='file' device='cdrom'>
              <source file='{iso_path}'/>
              <target dev='hda' bus='ide'/>
            </disk>
            <interface type='network'>
              <source network='default'/>
            </interface>
          </devices>
        </domain>
        """
        return self.conn.createXML(xml_config, 0)

    def list_vms(self):
        return [vm.name() for vm in self.conn.listAllDomains()]

    def stop_vm(self, name):
        vm = self.conn.lookupByName(name)
        vm.destroy()
