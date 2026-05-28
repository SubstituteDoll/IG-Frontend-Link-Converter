# Roadmap

This roadmap outlines the linear, feature-by-feature development plan for the link converter. To preserve project correctness and stability, tasks and their sub-components are recommended to be implemented and tested in the order specified below.

---

## Global Syntax Guide & Context Help (`-h`, `--help`)
*   [ ] **Command Help Output**
    *   [ ] Implement a complete syntax and flag configuration manual routed cleanly to stdout when `--help` or `-h` is supplied.
*   [ ] **Invalid Input Graceful Exit**
    *   [ ] Intercept any empty or malformed CLI command calls and output a streamlined, clear syntax usage summary to stderr before exiting with a standard failure code.

## Single URL Mode / Direct Argument (`--no-file`, `--direct-link`) [Enabled by Default]
*   [ ] **Direct Terminal IO**
    *   [ ] Establish default execution syntax: `./IGconvert [some URL] -OP [output platform]`.
    *   [ ] Enforce positional ordering: validate that the raw URL argument appears exactly as `argv[1]` immediately following the executable name.
    *   [ ] Implement leading-flag validation: if `argv[1]` begins with a hyphen `-` (except for `-f` or `--from-file`), immediately throw a syntax error and exit.
*   [ ] **Standard Stream Redirect**
    *   [ ] Route the single, transformed URL link string directly to stdout.

## Link Batch File Mode (`-f`, `--from-file`)
*   [ ] **File Stream Execution**
    *   [ ] Implement syntax: `./IGconvert -f [file name] -OP [output platform]`.
    *   [ ] Set up safe file input stream handlers to parse strings line-by-line.
*   [ ] **Output Generation**
    *   [ ] Design the program to generate and write all translated results into a new, distinct output text file.

## Required Target Specification (`-OP`, `--output-platform`)
*   [ ] **Output Format Enforcer**
    *   [ ] Implement CLI option parsing for `-OP` / `--output-platform` to define the target ecosystem for the output file.
    *   [ ] Enforce this flag as a hard requirement for execution, throwing a standard CLI usage error if omitted.
*   [ ] **Multi-Target Translation Engine**
    *   [ ] Expand the translation code to output correctly formatted links for all other supported frontend environments, rather than defaulting strictly to canonical Instagram URLs.

## Malformed URL Handling
*   [ ] **Detection**
    *   [ ] Implement strict structural checks to flag corrupted, truncated, or structurally invalid URL syntaxes before parsing.
*   [ ] **Automatic Fix Logic**
    *   [ ] Introduce heuristic rules to attempt recovery of common typos or missing protocol schemes (e.g., repairing missing `https://` prefixes).
    *   [ ] Implement contiguous sub-sequence detection to locate a valid URL inside a dirty line. This extracts the link for translation while leaving external annotations (e.g., trailing notes or status tags) entirely intact in the final output stream.
*   [ ] **Quarantine & Warning System**
    *   [ ] Route completely unfixable URLs to a secondary, dedicated quarantine output file.
        *   In single URL mode, no quarantine output file is produced.
    *   [ ] Print clean warnings to stderr alerting the user of the exact malformed link and line number.
    *   [ ] Structure the quarantine file output to prepend all warning strings at the top (line-by-line), followed immediately below by the raw unfixable quarantined lines themselves.

## Optional Explicit Input Constraints (`-IP`, `--input-platform`)
*   [ ] **Flag Parsing & Enforcement**
    *   [ ] Implement CLI option parsing for `-IP` / `--input-platform` to force the program to strictly evaluate incoming links against one targeted platform specification.
*   [ ] **Bypass Isolation (Non-Interference)**
    *   [ ] Ensure any incoming link belonging to a non-specified platform completely bypasses the translation and quarantine pipelines, surviving untouched into the output stream at its original relative line position.

## Automatic Input Platform Detection (`--auto`)
*   [ ] **Heterogeneous File Parsing**
    *   [ ] Enable the engine to dynamically scan and identify the host platform of every link on a line-by-line basis (active by default).
