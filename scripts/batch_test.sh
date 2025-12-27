#!/bin/bash

IMG_DIR = "../images"
OUT_DIR = "../output"

mkdir -p $OUT_DIR

for img in $IMG_DIR/*.jpg; do
    echo "Processing $img ..."
    ../build/RoadCrackDetection $img $OUT_DIR/$(basename $img)
done

echo "Batch processing done!"