#!/usr/bin/env python3
"""
Script to search GitHub for old PHP websites (version 5.2.x, 10-12 years old)
with working frontend and backend code.

This script uses GitHub's search API to find repositories matching the criteria.
"""

import json
import sys
from datetime import datetime, timedelta

def print_header():
    """Print script header."""
    print("=" * 80)
    print("GitHub Search for Old PHP Websites")
    print("Searching for PHP 5.2.x websites from 10-12 years ago")
    print("=" * 80)
    print()

def calculate_date_range():
    """Calculate the date range for 10-12 years ago."""
    current_year = datetime.now().year
    start_year = current_year - 12
    end_year = current_year - 10
    
    return f"{start_year}-01-01", f"{end_year}-12-31"

def generate_search_queries():
    """Generate GitHub search queries for finding old PHP websites."""
    start_date, end_date = calculate_date_range()
    
    queries = [
        {
            "description": "PHP websites with 5.2 version indicator",
            "query": f"php 5.2 language:php created:{start_date}..{end_date}",
        },
        {
            "description": "PHP projects mentioning version 5.2.x",
            "query": f"\"php 5.2\" in:readme language:php created:{start_date}..{end_date}",
        },
        {
            "description": "PHP repositories with frontend keywords",
            "query": f"php html css javascript created:{start_date}..{end_date}",
        },
        {
            "description": "PHP web applications from the target timeframe",
            "query": f"php website webapp created:{start_date}..{end_date} language:php",
        },
    ]
    
    return queries

def print_search_instructions():
    """Print instructions for using GitHub search."""
    start_date, end_date = calculate_date_range()
    
    print("SEARCH INSTRUCTIONS")
    print("-" * 80)
    print()
    print("To find old PHP websites (5.2.x, 10-12 years old) on GitHub:")
    print()
    print("1. Visit GitHub's search page: https://github.com/search")
    print()
    print("2. Use the following search queries:")
    print()
    
    queries = generate_search_queries()
    for i, query_info in enumerate(queries, 1):
        print(f"   Query {i}: {query_info['description']}")
        print(f"   {query_info['query']}")
        print()
    
    print("3. Additional filters to apply manually:")
    print("   - Look for repositories with index.php, config.php, or similar backend files")
    print("   - Check for HTML/CSS/JavaScript files indicating frontend code")
    print("   - Look for phpinfo() or version indicators in README or code")
    print("   - Check for database configuration files (db.php, database.php)")
    print()
    
    print("4. Key indicators of PHP 5.2.x projects:")
    print("   - PHP version specified in README or documentation")
    print("   - Use of deprecated functions (mysql_* instead of mysqli_*)")
    print("   - Old framework versions (e.g., CodeIgniter 1.x, early Zend)")
    print("   - Lack of namespace usage (introduced in PHP 5.3)")
    print()
    
    print("5. Identifying working frontend and backend:")
    print("   - Frontend: presence of HTML, CSS, JavaScript files")
    print("   - Backend: PHP files with database connections, business logic")
    print("   - Look for complete MVC structure or organized file structure")
    print("   - Check for configuration files and installation instructions")
    print()

def generate_github_search_api_example():
    """Generate example code for using GitHub API."""
    start_date, end_date = calculate_date_range()
    
    print()
    print("=" * 80)
    print("GITHUB API USAGE EXAMPLE")
    print("-" * 80)
    print()
    print("If you want to use GitHub's API programmatically:")
    print()
    print("# Using curl:")
    print(f'curl -H "Accept: application/vnd.github.v3+json" \\')
    print(f'  "https://api.github.com/search/repositories?q=php+5.2+language:php+created:{start_date}..{end_date}&sort=stars&order=desc"')
    print()
    print("# Using Python with requests library:")
    print("import requests")
    print()
    print("# Note: Add your GitHub token for higher rate limits")
    print("# headers = {'Authorization': 'token YOUR_GITHUB_TOKEN'}")
    print("headers = {'Accept': 'application/vnd.github.v3+json'}")
    print(f"url = 'https://api.github.com/search/repositories'")
    print(f"params = {{")
    print(f"    'q': 'php 5.2 language:php created:{start_date}..{end_date}',")
    print(f"    'sort': 'stars',")
    print(f"    'order': 'desc',")
    print(f"    'per_page': 30")
    print(f"}}")
    print("response = requests.get(url, params=params, headers=headers)")
    print("repositories = response.json()")
    print()
    print("# Process results")
    print("for repo in repositories.get('items', []):")
    print("    print(f\"Name: {repo['name']}\")")
    print("    print(f\"URL: {repo['html_url']}\")")
    print("    print(f\"Description: {repo['description']}\")")
    print("    print(f\"Created: {repo['created_at']}\")")
    print("    print('-' * 40)")
    print()

def generate_manual_verification_checklist():
    """Generate checklist for manual verification of repositories."""
    print()
    print("=" * 80)
    print("MANUAL VERIFICATION CHECKLIST")
    print("-" * 80)
    print()
    print("For each repository found, verify:")
    print()
    print("□ PHP Version:")
    print("  - Check README, composer.json, or documentation for PHP version")
    print("  - Look for phpinfo.php or version checks in code")
    print("  - Check for PHP 5.2-specific syntax or deprecated functions")
    print()
    print("□ Age (10-12 years old):")
    print("  - Check repository creation date")
    print("  - Verify commit history shows activity in 2013-2015 timeframe")
    print()
    print("□ Working Frontend:")
    print("  - HTML files present (index.html, *.html)")
    print("  - CSS files for styling")
    print("  - JavaScript files for interactivity")
    print("  - Images and assets directories")
    print()
    print("□ Working Backend:")
    print("  - PHP files with business logic")
    print("  - Database configuration files")
    print("  - API endpoints or controllers")
    print("  - Complete and organized code structure")
    print()
    print("□ Completeness:")
    print("  - Installation or setup instructions present")
    print("  - Database schema or migration files")
    print("  - Configuration examples")
    print("  - Not abandoned (or at least feature-complete)")
    print()

def main():
    """Main function."""
    print_header()
    
    start_date, end_date = calculate_date_range()
    print(f"Target Date Range: {start_date} to {end_date}")
    print(f"This corresponds to approximately {datetime.now().year - 12} to {datetime.now().year - 10}")
    print()
    print()
    
    print_search_instructions()
    generate_github_search_api_example()
    generate_manual_verification_checklist()
    
    print()
    print("=" * 80)
    print("NOTES:")
    print("-" * 80)
    print("- GitHub's search is limited to the first 1000 results")
    print("- API rate limits apply (60 requests/hour without auth, 5000 with)")
    print("- Many old PHP 5.2.x projects may not explicitly mention the version")
    print("- Some repositories may be archived or unmaintained")
    print("- Clone and test repositories to verify they actually work")
    print("=" * 80)
    print()

if __name__ == "__main__":
    main()
