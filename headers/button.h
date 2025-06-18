typedef struct {
    SDL_Rect rect;
    SDL_Color baseColor;
    SDL_Color hoverColor;
    SDL_Color textColor;
    const char *label;
    bool hovered;
} Button;