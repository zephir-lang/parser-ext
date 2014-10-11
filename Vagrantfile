VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
    config.vm.box = "ubuntu/trusty64"

    config.vm.provider "virtualbox" do |vb|
        vb.name = "zephir-parser"
        vb.memory = 1024
    end

    config.vm.provision :shell do |shell|
        shell.path = "scripts/vagrant.sh"
    end
end
