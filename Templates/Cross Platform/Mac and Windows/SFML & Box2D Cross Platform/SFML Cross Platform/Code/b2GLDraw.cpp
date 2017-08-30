#include "b2GLDraw.h"
#include <cstdio>
#include <cstdarg>
#include <cstring>

void b2GLDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    
    glColor4f(color.r, color.g, color.b, 0.5f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < vertexCount; i++) {
        b2Vec2 v = vertices[i];
        glVertex2f(v.x * 30, v.y * 30);
    }
    glEnd();
}

void b2GLDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    
    glColor4f(color.r, color.g, color.b, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < vertexCount; i++) {
        b2Vec2 v = vertices[i];
        glVertex2f(v.x * 30, v.y * 30);
    }
    glEnd();
}

void b2GLDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
    const float32 k_segments = 16.0f;
    const int vertexCount = 16;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    
    glColor4f(color.r, color.g, color.b, 1);
    glBegin(GL_LINE_LOOP);
    GLfloat glVertices[vertexCount * 2];
    for (int32 i = 0; i < k_segments; ++i) {
        b2Vec2 v = center + radius * b2Vec2(cos(theta), sin(theta));
        glVertex2f(v.x * 30, v.y * 30);
        theta += k_increment;
    }
    glEnd();
}

void b2GLDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
    const float32 k_segments = 16.0f;
    const int vertexCount = 16;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    
    glColor4f(color.r, color.g, color.b, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    GLfloat glVertices[vertexCount * 2];
    for (int32 i = 0; i < k_segments; ++i) {
        b2Vec2 v = center + radius * b2Vec2(cos(theta), sin(theta));
        glVertex2f(v.x * 30, v.y * 30);
        theta += k_increment;
    }
    glEnd();
    
    DrawSegment(center, center + radius*axis, color);
}

void b2GLDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
    glColor4f(color.r, color.g, color.b, 1);
    glBegin(GL_LINES);
    glVertex2f(p1.x * 30, p1.y * 30);
    glVertex2f(p2.x * 30, p2.y * 30);
    glEnd();
}

void b2GLDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
    glColor4f(color.r, color.g, color.b, 1);
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glVertex2f(p.x * 30, p.y * 30);
    glEnd();
}

void b2GLDraw::DrawString(int x, int y, const char *string, ...) {
    // TODO:
}

void b2GLDraw::DrawAABB(b2AABB* aabb, const b2Color& c) {
    
    glColor4f(c.r, c.g, c.b, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(aabb->lowerBound.x * 30, aabb->lowerBound.y * 30);
    glVertex2f(aabb->upperBound.x * 30, aabb->lowerBound.y * 30);
    glVertex2f(aabb->upperBound.x * 30, aabb->upperBound.y * 30);
    glVertex2f(aabb->lowerBound.x * 30, aabb->upperBound.y * 30);
    glEnd();
}

void b2GLDraw::DrawTransform(const b2Transform& xf) {
    
    b2Vec2 p1 = xf.p, p2;
    const float32 k_axisScale = 0.0f;
    
    p2 = p1 + k_axisScale * xf.q.GetXAxis();
    DrawSegment(p1, p2, b2Color(1, 0, 0));
    
    p2 = p1 + k_axisScale * xf.q.GetYAxis();
    DrawSegment(p1, p2, b2Color(0, 1, 0));
}
