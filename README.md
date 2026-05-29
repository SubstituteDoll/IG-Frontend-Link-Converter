# IG-Frontend-Link-Converter

A lightweight, POSIX C program designed to rescue orphaned links from dead alternative Instagram frontends by converting them back into active canonical Instagram URLs, or to other live alternative frontends.

## Motivation

The alternative frontend ecosystem is volatile. When popular frontends like `picuki.com` suddenly go offline or change structures, they leave behind vast webs of unarchived, broken URLs. 

However, because these alternative frontends build their links using Instagram's underlying URL structure, the data may not be truly lost. This project bridges the gap: it decodes orphaned frontend URLs back into functional links. Not only to official Instagram links, but also to other live alternative frontends.

## Features

* **File-Based Processing:** Reads, processes, and cleanly produces converted versions of massive batch link files.
* **Supported Domains:**
  * `picuki.com`
  * `picuki.site`
  * `instagram.com`
  * `imginn.com`
  
  *(Note: The operational status or "liveness" of any given platform is determined manually by maintainers. If any of these listed frontends go down, please open a GitHub Issue to raise awareness.)*

## Usage

### Platform Compatibility Limitation
This tool is strictly coded and tested for **Linux and POSIX-compliant environments**. It relies on standard POSIX file stream operations for fast and safe file creation.

### Quick Start

1. **Build the Program**  
   Compile the release source files using the provided Makefile:
   ```bash
   make
   ```
   *Alternatively, if you are developing or testing and want to enable macro-driven debugging outputs on stderr, compile using the debug target:*
   ```bash
   make debug
   ```

2. **Prepare Your Link File**  
   Create your source text file containing the raw URLs (one per line).

3. **Execute the Program**  
   Run the compiled utility from your terminal, passing the target input file configuration to generate the converted output file:
   ```bash
   ./converter [arguments]
   ```

4. **Clean Build Artifacts**  
   Remove intermediate object files and reset your directory state:
   ```bash
   make clean
   ```
---
*Contributions to expand support for other historical or active alternative frontends are welcome via Pull Requests.*

