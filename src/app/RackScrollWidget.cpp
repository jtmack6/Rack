#include "app/RackScrollWidget.hpp"
#include "app/Scene.hpp"
#include "window.hpp"
#include "context.hpp"


namespace rack {


void RackScrollWidget::step() {
	Vec pos = context()->window->mousePos;
	Rect viewport = getViewport(box.zeroPos());
	// Scroll rack if dragging cable near the edge of the screen
	if (context()->scene->rackWidget->wireContainer->activeWire) {
		float margin = 20.0;
		float speed = 15.0;
		if (pos.x <= viewport.pos.x + margin)
			offset.x -= speed;
		if (pos.x >= viewport.pos.x + viewport.size.x - margin)
			offset.x += speed;
		if (pos.y <= viewport.pos.y + margin)
			offset.y -= speed;
		if (pos.y >= viewport.pos.y + viewport.size.y - margin)
			offset.y += speed;
	}
	ScrollWidget::step();
}


} // namespace rack
