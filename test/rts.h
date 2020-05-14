#pragma once

/* ***** Setup and cleanup functions for RTS ***** */
static int process_arguments(int argc, char** argv) { abort(); }
static void setup_rts(void) { setup_library(); }
static void cleanup_rts(void) { cleanup_library(); }

// this is needed for some reason:
static bool have_exception = false;
