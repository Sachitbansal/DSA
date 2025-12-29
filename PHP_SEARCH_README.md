# Finding Old PHP 5.2.x Websites on GitHub (10-12 Years Old)

## Overview

This repository contains tools and documentation to help you search GitHub for old PHP websites that:
- Use PHP version 5.2.x (or are from that era)
- Were created approximately 10-12 years ago (2013-2015 timeframe)
- Have both working frontend and backend code
- Are complete, functional web applications

## Quick Start

### Option 1: Use the Interactive Script

Run the comprehensive search guide generator:

```bash
python3 github_php_search.py
```

This will display:
- Ready-to-use GitHub search URLs
- Verification criteria
- PHP 5.2.x specific indicators
- API usage examples

### Option 2: Use the Basic Script

Run the basic search instruction generator:

```bash
python3 find_old_php_websites.py
```

### Option 3: Direct GitHub Search

Click on these pre-configured search links:

1. **[PHP 5.2 Repositories (2013-2015)](https://github.com/search?q=php+5.2+language%3Aphp+created%3A2013-01-01..2015-12-31&type=repositories)**
2. **[PHP 5.2 in README (2013-2015)](https://github.com/search?q=%22php+5.2%22+in%3Areadme+language%3Aphp+created%3A2013-01-01..2015-12-31&type=repositories)**
3. **[PHP Web Apps (2013-2015)](https://github.com/search?q=php+webapp+language%3Aphp+created%3A2013-01-01..2015-12-31&type=repositories)**
4. **[PHP with Frontend Tech (2013-2015)](https://github.com/search?q=php+html+css+javascript+created%3A2013-01-01..2015-12-31&type=repositories)**
5. **[Old PHP Frameworks (2013-2015)](https://github.com/search?q=%28CodeIgniter+OR+Zend+OR+CakePHP%29+language%3Aphp+created%3A2013-01-01..2015-12-31&type=repositories)**

## Search Criteria

### PHP Version Indicators

When examining repositories, look for:

- ✅ **composer.json** mentioning PHP 5.2.x
- ✅ **README** files documenting PHP version
- ✅ **Deprecated functions**: `mysql_connect()`, `mysql_query()`, `ereg()`, `split()`
- ✅ **Absence of namespaces** (introduced in PHP 5.3)
- ✅ **PHP 4-style constructors** (method name same as class name)

### Age Verification (10-12 Years)

- ✅ Repository created between **2013-01-01** and **2015-12-31**
- ✅ Active development during that timeframe
- ✅ Commit history from 2013-2015

### Frontend Components

Look for these files/directories:

- ✅ **HTML files**: `index.html`, `*.html`, template files
- ✅ **CSS files**: `style.css`, `assets/css/`, `css/`
- ✅ **JavaScript**: `main.js`, `scripts.js`, `assets/js/`, `js/`
- ✅ **Images**: `images/`, `assets/`, `uploads/`
- ✅ **Templates**: `.tpl`, `.phtml` files

### Backend Components

Look for these PHP components:

- ✅ **Entry point**: `index.php`
- ✅ **Configuration**: `config.php`, `settings.php`
- ✅ **Database**: `db.php`, `database.php`, `.sql` schema files
- ✅ **MVC structure**: `models/`, `views/`, `controllers/`
- ✅ **Business logic**: Multiple PHP files with classes/functions
- ✅ **Authentication**: Login/session management
- ✅ **API endpoints** or routing system

### Completeness

A complete project should have:

- ✅ **Installation instructions** (README or INSTALL file)
- ✅ **Database schema** (.sql files)
- ✅ **Configuration examples** (config.sample.php)
- ✅ **Multiple components** (not just a single file)
- ✅ **Documentation** or comments

## PHP 5.2.x Specific Features

### Deprecated Functions (Removed in Later Versions)

These functions indicate PHP 5.2.x or earlier:

```php
// Old MySQL extension (removed in PHP 7.0)
mysql_connect($host, $user, $pass);
mysql_query($sql);
mysql_fetch_array($result);

// POSIX regex (removed in PHP 5.3)
ereg($pattern, $string);
eregi($pattern, $string);
split($pattern, $string);

// Session functions (deprecated in 5.3)
session_register($name);
session_unregister($name);
```

### Missing Features (Added After 5.2)

PHP 5.2 code will NOT have:

- ❌ Namespaces (`namespace App\Controllers;`)
- ❌ Late static binding (`static::method()`)
- ❌ Closures/anonymous functions
- ❌ `__DIR__` constant
- ❌ Ternary shorthand (`?:`)
- ❌ Traits

### Common PHP 5.2 Patterns

```php
// PHP 4-style constructors (deprecated in 5.3)
class MyClass {
    function MyClass() {  // Constructor has same name as class
        // ...
    }
}

// Global variables
global $db, $config;

// Old error handling
error_reporting(E_ALL ^ E_NOTICE);

// MySQL old extension
$conn = mysql_connect($host, $user, $pass);
mysql_select_db($database, $conn);
```

## Example Repository Structure

A typical PHP 5.2.x website structure:

```
project-root/
├── index.php              # Main entry point
├── config.php             # Configuration file
├── db.php                 # Database connection
├── README.md              # Documentation
├── install.sql            # Database schema
├── .htaccess              # Apache configuration
│
├── admin/                 # Admin panel
│   ├── index.php
│   ├── dashboard.php
│   └── users.php
│
├── includes/              # Shared PHP includes
│   ├── functions.php
│   ├── header.php
│   └── footer.php
│
├── css/                   # Stylesheets
│   ├── style.css
│   └── admin.css
│
├── js/                    # JavaScript files
│   ├── main.js
│   └── jquery.min.js
│
├── images/                # Static images
│   └── logo.png
│
└── uploads/               # User-uploaded content
    └── .htaccess
```

## Programmatic Search

### Using GitHub CLI

```bash
# Search for PHP 5.2 repos from 2013-2015
gh search repos "php 5.2 language:php created:2013-01-01..2015-12-31" \
  --sort stars \
  --order desc \
  --limit 30
```

### Using cURL

```bash
curl -H "Accept: application/vnd.github.v3+json" \
     -H "Authorization: token YOUR_GITHUB_TOKEN" \
     "https://api.github.com/search/repositories?q=php+5.2+language:php+created:2013-01-01..2015-12-31&sort=stars&order=desc&per_page=30"
```

### Using Python

```python
import requests

# GitHub API setup
token = "YOUR_GITHUB_TOKEN"
headers = {
    'Accept': 'application/vnd.github.v3+json',
    'Authorization': f'token {token}'
}

# Search parameters
params = {
    'q': 'php 5.2 language:php created:2013-01-01..2015-12-31',
    'sort': 'stars',
    'order': 'desc',
    'per_page': 30
}

# Execute search
response = requests.get(
    'https://api.github.com/search/repositories',
    headers=headers,
    params=params
)

# Process results
data = response.json()
print(f"Found {data['total_count']} repositories\n")

for repo in data.get('items', []):
    print(f"Name: {repo['full_name']}")
    print(f"URL: {repo['html_url']}")
    print(f"Stars: {repo['stargazers_count']}")
    print(f"Created: {repo['created_at']}")
    print(f"Description: {repo['description']}")
    print('-' * 80)
```

## Verification Checklist

When you find a potential repository, verify:

- [ ] **PHP Version**: Check README, composer.json, or code for PHP 5.2.x indicators
- [ ] **Age**: Repository created between 2013-2015
- [ ] **Frontend**: HTML, CSS, JavaScript files present
- [ ] **Backend**: PHP files with business logic and database code
- [ ] **Database**: .sql schema or migration files included
- [ ] **Configuration**: Config files or examples present
- [ ] **Documentation**: README with installation instructions
- [ ] **Completeness**: Not just a code snippet; full working application
- [ ] **Activity**: Check if it was actively developed (not just initialized)

## Advanced Search Tips

### Combine Multiple Criteria

```
php 5.2 mysql html css created:2013-01-01..2015-12-31 stars:>5
```

### Search in Specific Files

```
mysql_connect in:file language:php created:2013-01-01..2015-12-31
```

### Find Specific Frameworks

```
CodeIgniter language:php created:2013-01-01..2015-12-31
```

### Exclude Forks

```
php 5.2 language:php created:2013-01-01..2015-12-31 fork:false
```

## Common PHP 5.2.x Frameworks

Popular frameworks from that era:

- **CodeIgniter 1.x / 2.x** - Lightweight MVC framework
- **Zend Framework 1.x** - Enterprise framework
- **CakePHP 1.x / 2.x** - Rapid development framework
- **Symfony 1.x** - Full-stack framework
- **Yii 1.x** - High-performance framework

Search for these specifically:

```
CodeIgniter OR "Zend Framework" OR CakePHP created:2013-01-01..2015-12-31
```

## Important Notes

⚠️ **Limitations:**
- GitHub search is limited to the first 1,000 results per query
- API rate limits: 60 requests/hour (unauthenticated), 5,000/hour (authenticated)
- Many old projects may not explicitly mention PHP version
- Some repositories may have been deleted, archived, or made private

⚠️ **Security:**
- Old PHP 5.2.x code may have security vulnerabilities
- Do NOT use deprecated functions in production code
- These repositories are for educational/research purposes

⚠️ **Testing:**
- Clone repositories locally to test functionality
- May require old PHP versions to run (use Docker or VMs)
- Database schemas may need updates for modern MySQL/MariaDB

## License & Usage

When using code from found repositories:
- Always check the repository's license
- Respect copyright and attribution requirements
- Many old projects may not have explicit licenses
- Consider modernizing code before production use

## Getting a GitHub Token

To increase API rate limits:

1. Go to https://github.com/settings/tokens
2. Click "Generate new token (classic)"
3. Select scopes: `public_repo` (minimum)
4. Copy and save your token
5. Use in API calls or set as environment variable:
   ```bash
   export GITHUB_TOKEN="your_token_here"
   ```

## Resources

- [GitHub Search Syntax](https://docs.github.com/en/search-github/getting-started-with-searching-on-github/understanding-the-search-syntax)
- [GitHub REST API - Search](https://docs.github.com/en/rest/search)
- [PHP 5.2 Documentation](https://www.php.net/releases/5_2_17.php) (archived)
- [PHP Migration Guides](https://www.php.net/manual/en/appendices.php)

## Contributing

If you find this guide helpful or have suggestions for improvement:
- Report issues or suggest enhancements
- Share successful search queries
- Document interesting repositories you find

---

**Generated:** 2025-12-29  
**Target PHP Version:** 5.2.x  
**Target Timeframe:** 2013-2015 (10-12 years ago)
