# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Step-by-Step                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 12:54:06 by msakurad          #+#    #+#              #
#    Updated: 2023/08/18 12:54:12 by msakurad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


1. Download the latest stable version of the installation image of Debian.
	Debian


2. Install AppArmor 
	AppArmor for Debian must be running at startup.
	https://gitlab.com/apparmor/apparmor/-/wikis/GettingStarted
	AppArmor is Mandatory Access Control (MAC) like security system for Linux.	
	AppArmor confines individual programs to a set of files, capabilities, network access and rlimits, collectively known as the AppArmor policy for the program, or simply as a profile. New or modified policy can be applied to the running system without a reboot.


3. Create at least 2 encrypted partitions using LVM.
	LVM - Logical Volume Manager
	https://linuxuniverse.com.br/linux/lvm


4. Package Management
	apt, apt-get, aptitude


5. Configure a SSH service
	- on port 4242 only
	- for security reasons, it must not be	possible to connect using SSH as root.
	- set up a new account
	- connect to the VM through other machine


6. Install the UFW firewall
	- UFW - Uncomplicated FireWall
	- Linux firewall
	- https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu-20-04-pt
	- enable only port 4242 open
	- firewall must be active when the VM is launched.


7. Define the hostname
	- standard hostname: msakurad42


8. Install and configure sudo
	- User: root
	- User: msakurad - this user has to belong to the user42 and sudo groups.
	- Create a new user and assign it to a group.


	Requirements:
	- Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
	- A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
	- Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
	- The TTY mode has to be enabled for security reasons.
	- For security reasons too, the paths that can be used by sudo must be restricted.
		Example:
		/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin


9. Implement a strong password policy
	- Your password has to expire every 30 days.
	- The minimum number of days allowed before the modification of a password will be set to 2.
	- The user has to receive a warning message 7 days before their password expires.
	- Your password must be at least 10 characters long. It must contain an uppercase letter, a lowercase letter, and a number. Also, it must not contain more than 3 consecutive identical characters.
	- The password must not include the name of the user.
	- The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
	- Of course, your root password has to comply with this policy.


	- After setting up your configuration files, you will have to change all the passwords of the accounts present on the virtual machine, including the root account.

10. Create a simple script called monitoring.sh.
	- It must be developed in bash.
	- At server startup, the script will display some information (listed below) on all terminals every 10 minutes (take a look at wall).
	- The banner is optional. No error must be visible.
	
	
	Your script must always be able to display the following information:
	- The architecture of your operating system and its kernel version.
	- The number of physical processors.
	- The number of virtual processors.
	- The current available RAM on your server and its utilization rate as a percentage.
	- The current available memory on your server and its utilization rate as a percentage.
	- The current utilization rate of your processors as a percentage.
	- The date and time of the last reboot.
	- Whether LVM is active or not.
	- The number of active connections.
	- The number of users using the server.
	- The IPv4 address of your server and its MAC (Media Access Control) address.
	- The number of commands executed with the sudo program.
	- During the defense, you will be asked to explain how this script works. You will also have to interrupt it without modifying it.
	- Take a look at cron.

11. Commands to check some of the subject's requirements:
	head -n 2 /etc/os-release
	/usr/sbin/aa-status
	ss -tunlp
	/usr/sbin/ufw status

12. Make the signature.txt file
	- Paste in it the signature of your machine’s virtual disk.
	
	
	To get this signature, you first have to open the default installation folder (it is the folder where your VMs are saved):
		- Windows: %HOMEDRIVE%%HOMEPATH%\VirtualBox VMs\
		-  Linux: ~/VirtualBox VMs/


	Then, retrieve the signature from the ".vdi" file (or ".qcow2 for UTM’users) of your virtual machine in sha1 format.
	Below are 4 command examples for a rocky_serv.vdi file:
	- Windows: certUtil -hashfile rocky_serv.vdi sha1
	- Linux: sha1sum rocky_serv.vdi