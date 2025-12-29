#!/usr/bin/env python3
"""
Advanced GitHub Search Script for Old PHP Websites

This script uses GitHub's search API to find PHP websites from 10-12 years ago
(PHP 5.2.x era) with both frontend and backend code.
"""

import json
import sys
from datetime import datetime

def print_banner():
    """Print search banner."""
    print("╔" + "=" * 78 + "╗")
    print("║" + " " * 15 + "GitHub Search: Old PHP 5.2.x Websites" + " " * 25 + "║")
    print("║" + " " * 20 + "(10-12 Years Old, 2013-2015)" + " " * 28 + "║")
    print("╚" + "=" * 78 + "╝")
    print()

def get_date_range():
    """Calculate date range for 10-12 years ago."""
    current_year = datetime.now().year
    start_date = f"{current_year - 12}-01-01"
    end_date = f"{current_year - 10}-12-31"
    return start_date, end_date

def print_search_queries():
    """Print recommended search queries."""
    start_date, end_date = get_date_range()
    
    print("📋 RECOMMENDED SEARCH QUERIES")
    print("─" * 80)
    print()
    
    queries = [
        {
            "name": "Query 1: Direct PHP 5.2 Mention",
            "query": f'php 5.2 language:php created:{start_date}..{end_date}',
            "url": f'https://github.com/search?q=php+5.2+language%3Aphp+created%3A{start_date}..{end_date}&type=repositories'
        },
        {
            "name": "Query 2: PHP 5.2 in README",
            "query": f'"php 5.2" in:readme language:php created:{start_date}..{end_date}',
            "url": f'https://github.com/search?q=%22php+5.2%22+in%3Areadme+language%3Aphp+created%3A{start_date}..{end_date}&type=repositories'
        },
        {
            "name": "Query 3: PHP Web Applications",
            "query": f'php webapp language:php created:{start_date}..{end_date}',
            "url": f'https://github.com/search?q=php+webapp+language%3Aphp+created%3A{start_date}..{end_date}&type=repositories'
        },
        {
            "name": "Query 4: PHP with Frontend Technologies",
            "query": f'php html css javascript created:{start_date}..{end_date}',
            "url": f'https://github.com/search?q=php+html+css+javascript+created%3A{start_date}..{end_date}&type=repositories'
        },
        {
            "name": "Query 5: Old PHP Frameworks",
            "query": f'(CodeIgniter OR Zend OR CakePHP) language:php created:{start_date}..{end_date}',
            "url": f'https://github.com/search?q=%28CodeIgniter+OR+Zend+OR+CakePHP%29+language%3Aphp+created%3A{start_date}..{end_date}&type=repositories'
        },
        {
            "name": "Query 6: PHP with MySQL (old extension)",
            "query": f'mysql_connect language:php created:{start_date}..{end_date}',
            "url": f'https://github.com/search?q=mysql_connect+language%3Aphp+created%3A{start_date}..{end_date}&type=code'
        }
    ]
    
    for i, q in enumerate(queries, 1):
        print(f"{i}. {q['name']}")
        print(f"   Query: {q['query']}")
        print(f"   URL: {q['url']}")
        print()
    
    print()

def print_verification_criteria():
    """Print criteria for verifying found repositories."""
    print("✓ VERIFICATION CRITERIA")
    print("─" * 80)
    print()
    print("For each repository found, verify the following:")
    print()
    print("🔧 PHP Version Indicators:")
    print("  • composer.json with PHP version constraint")
    print("  • phpinfo() calls in code")
    print("  • README mentioning PHP 5.2.x")
    print("  • Use of deprecated mysql_* functions (not mysqli_* or PDO)")
    print("  • Absence of namespaces (added in PHP 5.3)")
    print("  • Use of old error reporting methods")
    print()
    print("📅 Age Verification (10-12 years old):")
    print("  • Repository created between 2013-2015")
    print("  • Commit history from that timeframe")
    print("  • Last meaningful commit in that era")
    print()
    print("🎨 Frontend Components:")
    print("  • HTML files (index.html, templates/*.html)")
    print("  • CSS stylesheets (style.css, assets/css/)")
    print("  • JavaScript files (scripts.js, assets/js/)")
    print("  • Images and media assets")
    print("  • Template files (.tpl, .phtml)")
    print()
    print("⚙️  Backend Components:")
    print("  • PHP files with business logic")
    print("  • Database configuration (config.php, db.php)")
    print("  • MVC structure (models/, views/, controllers/)")
    print("  • API endpoints or routing")
    print("  • Session management")
    print("  • Authentication/authorization code")
    print()
    print("📦 Completeness:")
    print("  • Installation instructions")
    print("  • Database schema (.sql files)")
    print("  • Configuration examples")
    print("  • Dependencies documented")
    print("  • Not just a code snippet or incomplete project")
    print()
    print()

def print_php52_indicators():
    """Print specific PHP 5.2.x indicators."""
    print("🔍 PHP 5.2.x SPECIFIC INDICATORS")
    print("─" * 80)
    print()
    print("Look for these PHP 5.2-era patterns:")
    print()
    print("Deprecated Functions (only in PHP 5.2.x):")
    print("  • mysql_connect(), mysql_query(), mysql_fetch_array()")
    print("  • ereg(), eregi(), split() - POSIX regex functions")
    print("  • session_register(), session_unregister()")
    print("  • call_user_method(), call_user_method_array()")
    print()
    print("Missing Features (added after 5.2):")
    print("  • No namespace declarations (added in 5.3)")
    print("  • No late static binding (static::)")
    print("  • No closures or anonymous functions")
    print("  • No goto statement")
    print("  • No __DIR__ constant")
    print("  • No ternary shorthand (?:)")
    print()
    print("Common Patterns:")
    print("  • Old framework versions (CodeIgniter 1.x, Zend 1.x)")
    print("  • PHP 4 constructor naming (same as class name)")
    print("  • Global variable usage")
    print("  • Register globals support")
    print()
    print()

def print_usage_instructions():
    """Print usage instructions."""
    print("📖 HOW TO USE THIS GUIDE")
    print("─" * 80)
    print()
    print("Step 1: Use the search queries above")
    print("        - Click on the provided URLs or copy queries to GitHub search")
    print("        - Sort by 'Most stars' or 'Recently updated' for better results")
    print()
    print("Step 2: Filter results")
    print("        - Check repository age (created 2013-2015)")
    print("        - Look for PHP projects with multiple file types")
    print("        - Prefer projects with more than 10 stars for quality")
    print()
    print("Step 3: Verify each repository")
    print("        - Browse the repository structure")
    print("        - Check for both PHP backend and HTML/CSS/JS frontend")
    print("        - Look for PHP version indicators")
    print("        - Verify it's a complete project, not a fragment")
    print()
    print("Step 4: Document findings")
    print("        - Record repository URL")
    print("        - Note PHP version (if found)")
    print("        - List frontend and backend components")
    print("        - Check if project is complete/working")
    print()
    print()

def print_api_examples():
    """Print API usage examples."""
    start_date, end_date = get_date_range()
    
    print("💻 PROGRAMMATIC SEARCH (GitHub API)")
    print("─" * 80)
    print()
    print("Using curl:")
    print("─" * 40)
    print(f"""
curl -H "Accept: application/vnd.github.v3+json" \\
     -H "Authorization: token YOUR_TOKEN" \\
     "https://api.github.com/search/repositories?q=php+5.2+language:php+created:{start_date}..{end_date}&sort=stars&order=desc&per_page=30"
""")
    
    print("Using Python:")
    print("─" * 40)
    print(f"""
import requests

# Setup
token = "YOUR_GITHUB_TOKEN"  # Get from https://github.com/settings/tokens
headers = {{
    'Accept': 'application/vnd.github.v3+json',
    'Authorization': f'token {{token}}'
}}

# Search parameters
params = {{
    'q': 'php 5.2 language:php created:{start_date}..{end_date}',
    'sort': 'stars',
    'order': 'desc',
    'per_page': 30
}}

# Execute search
response = requests.get(
    'https://api.github.com/search/repositories',
    headers=headers,
    params=params
)

# Process results
data = response.json()
print(f"Found {{data['total_count']}} repositories")

for repo in data.get('items', []):
    print(f"\\nRepository: {{repo['full_name']}}")
    print(f"URL: {{repo['html_url']}}")
    print(f"Stars: {{repo['stargazers_count']}}")
    print(f"Created: {{repo['created_at']}}")
    print(f"Description: {{repo['description']}}")
""")
    print()

def print_example_repositories():
    """Print examples of what to look for."""
    print("📚 EXAMPLE REPOSITORY PATTERNS")
    print("─" * 80)
    print()
    print("Good indicators of complete PHP 5.2.x websites:")
    print()
    print("Directory Structure Example:")
    print("─" * 40)
    print("""
project-root/
├── index.php              # Entry point
├── config.php             # Configuration
├── db.php                 # Database connection
├── README.md              # Documentation
├── install.sql            # Database schema
├── admin/                 # Admin panel
│   ├── index.php
│   └── dashboard.php
├── includes/              # Shared PHP files
│   ├── functions.php
│   └── header.php
├── css/                   # Stylesheets
│   └── style.css
├── js/                    # JavaScript
│   └── main.js
├── images/                # Images
└── uploads/               # User uploads
""")
    print()
    print("File Indicators:")
    print("─" * 40)
    print("  ✓ Multiple .php files (not just one)")
    print("  ✓ At least one .sql or database file")
    print("  ✓ CSS and JS directories or files")
    print("  ✓ HTML templates or includes")
    print("  ✓ Configuration file examples")
    print("  ✓ README with setup instructions")
    print()
    print()

def main():
    """Main function."""
    print_banner()
    
    start_date, end_date = get_date_range()
    print(f"🗓️  Target Timeframe: {start_date} to {end_date}")
    print(f"   (Approximately {datetime.now().year - 12} to {datetime.now().year - 10})")
    print()
    print()
    
    print_search_queries()
    print_verification_criteria()
    print_php52_indicators()
    print_example_repositories()
    print_usage_instructions()
    print_api_examples()
    
    print("⚠️  IMPORTANT NOTES")
    print("─" * 80)
    print("• GitHub search is limited to 1,000 results per query")
    print("• API rate limits: 60/hour (unauthenticated), 5,000/hour (authenticated)")
    print("• Many PHP 5.2.x projects may not explicitly mention the version number")
    print("• Some repositories may be archived, deleted, or made private")
    print("• Always clone and test locally to verify functionality")
    print("• Respect repository licenses when using code")
    print()
    print("═" * 80)
    print("Search guide generated successfully!")
    print("═" * 80)

if __name__ == "__main__":
    main()
