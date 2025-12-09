RES=$(xrandr | grep '*' | awk '{print $1}')
WIDTH=${RES%x*}
HEIGHT=${RES#*x}

#xsetwacom set "Note9 S-Pen Tablet stylus" MapToOutput $RES+0+0
xsetwacom set "Note9 S-Pen Tablet stylus" Rotate cw
