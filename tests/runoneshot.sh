#!/bin/sh

set -e

for data in interrupts-data-*; do
    echo "Test with $data..." >&2
    IRQBALANCE_PROC_INTERRUPTS="$data" ../irqbalance --debug --oneshot --foreground
done

