# This Puppet manifest configures Nginx with a custom HTTP header X-Served-By
# which contains the hostname of the server.

# Ensure the hostname command is available
exec { 'hostnamectl set-hostname $(hostname)':
  path => '/usr/bin:/usr/sbin:/bin:/sbin',
}

# Install Nginx
package { 'nginx':
  ensure => installed,
}

# Ensure the Nginx service is enabled and running
service { 'nginx':
  ensure    => running,
  enable    => true,
  subscribe => File['/etc/nginx/sites-available/default'],
}

# Configure Nginx to include the custom header
file { '/etc/nginx/sites-available/default':
  ensure  => file,
  content => template('nginx/default.erb'),
  notify  => Service['nginx'],
}

# Template for the Nginx default site configuration
file { '/etc/puppetlabs/code/environments/production/modules/nginx/templates/default.erb':
  ensure  => file,
  content => @("EOF")
server {
    listen 80 default_server;
    listen [::]:80 default_server;

    root /var/www/html;
    index index.html index.htm index.nginx-debian.html;

    server_name _;

    location / {
        try_files \$uri \$uri/ =404;
        add_header X-Served-By $hostname;
    }
}
| EOF
}
