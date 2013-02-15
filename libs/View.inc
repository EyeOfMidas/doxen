<?php
class View {
    public function render($viewName, array $viewData) {
        ob_start();
        extract($viewData, EXTR_OVERWRITE);
        include(VIEWROOT. $viewName);
        $view = ob_get_contents();
        ob_end_clean();
        return $view;
    }
}
