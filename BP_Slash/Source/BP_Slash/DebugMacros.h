#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, THIRTY, FColor::Red, false, 30.f)
#define DRAW_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, THIRTY, FColor::Red, false, -1.f)
#define DRAW_FORWARD_LINE(Location, Forward) if (GetWorld()) DrawDebugLine(GetWorld(), Location,Forward, FColor::Red, true, -1.f, 0, 1.f)
#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location,25, FColor::Red, true)
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) {\
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
	DrawDebugPoint(GetWorld(), EndLocation,25, FColor::Red, true);\
	DrawDebugPoint(GetWorld(), StartLocation, 25, FColor::Red, true);\
} 