
# doxen

====

<img src="http://i.imgur.com/RMM7Nni.jpg" title="Hosted by imgur.com" alt="" width="200" align="right" />

A very lightweight forum implementation.

---

### Requirements

This was only tested on a debian linux server, so that's the baseline. You will need apache2, PHP5.3 +suhosin if you haven't changed your PHP session storage location. MySQL server is used for the backend, and Memcached is optional but suggested.

### Installation

To set up your own instance of doxen, just copy the **setup/apache2_doxen** vhost definition to your apache2 configuration. For me this is
```sudo cp setup/apache2_doxen /etc/apache2/sites-available/

sudo ln -s /etc/apache2/sites-available/apache2_doxen /etc/apache2/sites-enabled/001-doxen

sudo /etc/init.d/apache2 restart```

The mysql database setup script is in **setup/mysql_db.sql** and will create the required database and tables.
Make sure to change the default user password in this file, just replace 'doxenpassword'.

```mysql -u root -p < setup/mysql_db.sql```

The code should be placed in **/var/www/doxen**. The **config.inc** file has configuration information, make sure that the database password here matches what you changed the password to in the database script.

Once you are setup, delete the entire **setup** folder as you will no longer need it.
