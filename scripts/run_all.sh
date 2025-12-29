#!/bin/bash

IMG_DIR="../data/images"
OUT_DIR="../data/output"

mkdir -p $OUT_DIR

for img in $IMG_DIR/*.jpg; do
    echo "Processing $img ..."
    ../build/RoadCrackDetection "$img" "$OUT_DIR/$(basename $img)"
done

echo "Batch processing done!"