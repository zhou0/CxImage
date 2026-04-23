cmake_minimum_required(VERSION 3.5)
project(libpsd C)
add_library(libpsd STATIC
    adjustment.c bevel_emboss.c bitmap.c blend.c boundary.c brightness_contrast.c channel_image.c channel_mixer.c color.c color_balance.c color_mode.c color_overlay.c curves.c descriptor.c drop_shadow.c effects.c file_header.c fixed.c gaussian_blur.c gradient_blend.c gradient_fill.c gradient_map.c gradient_overlay.c hue_saturation.c image_data.c image_resource.c inner_glow.c inner_shadow.c invert.c layer_mask.c levels.c outer_glow.c path.c pattern.c pattern_fill.c pattern_overlay.c photo_filter.c posterize.c psd.c psd_system.c psd_zip.c rect.c satin.c selective_color.c solid_color.c stream.c stroke.c threshold.c thumbnail.c type_tool.c
)
target_include_directories(libpsd PUBLIC . ${CMAKE_CURRENT_SOURCE_DIR}/../zlib)
