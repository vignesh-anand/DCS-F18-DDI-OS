-- Hornet main on internal; right-hand DDI on external portrait-flipped
_ = function(p) return p; end

name        = _('Hornet_RightDDI')
Description = 'Main cockpit on internal 2880×1800; right DDI on external 720×720 (portrait)'

-- ===================================================================
-- Viewports
-- ===================================================================
Viewports = {
  Center = {
    -- Primary (internal) display
    x      = 0;          -- left edge of main
    y      = 0;          -- top edge
    width  = 2880;       -- internal display width
    height = 1800;       -- internal display height
    viewDx = 0;
    viewDy = 0;
    aspect = screen.aspect;  -- 2880/1800 = 1.6
  },
}

-- ===================================================================
-- Right DDI (MFCD) on your second 720×720 monitor
-- ===================================================================
RIGHT_MFCD = {
  x      = 2880;       -- sits immediately to the right of main
  y      = 0;          -- top-aligned
  width  = 720;        -- your LCD’s width
  height = 720;        -- your LCD’s height
}

-- Make sure all UIs (JTAC, radio menus, etc.) still land on the main view:
UIMainView       = Viewports.Center
GU_MAIN_VIEWPORT = Viewports.Center
