
# doxen

====

<img src="http://i.imgur.com/RMM7Nni.jpg" title="Hosted by imgur.com" alt="" width="200" align="right" />

A very lightweight forum implementation.

---

### Requirements

This was only tested on a debian linux server, so that's the baseline. You will need apache2, PHP5.3 +suhosin if you haven't changed your PHP session storage location. MySQL server is used for the backend, and Memcached is optional but suggested.

### Installation

To set up your own instance of doxen, just copy the **setup/apache2_doxen** vhost definition to your apache2 configuration.

For the database, create the user **doxen**. The default db name is "doxen", make sure the user has select, insert and delete. The mysql database setup script is in **setup/mysql_db.sql** and will create the required database and tables.

The code should be placed in **/var/www/doxen**.
