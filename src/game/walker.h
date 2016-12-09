#pragma once

#include "data/entity.h"
#include "lmath.h"
#include "BulletCollision/CollisionDispatch/btCollisionWorld.h"

namespace VI
{

struct RigidBody;

struct Walker : public ComponentType<Walker>
{
	static Vec3 get_support_velocity(const Vec3&, const btCollisionObject*);

	static r32 default_capsule_height;
	static r32 default_support_height;

	Vec2 dir;
	r32 height,
		support_height,
		radius,
		mass,
		speed,
		max_speed,
		rotation,
		target_rotation,
		rotation_speed,
		air_control_accel,
		accel1,
		accel2,
		accel_threshold,
		deceleration,
		net_speed,
		net_speed_timer;
	u32 obstacle_id;
	Ref<RigidBody> support;
	LinkArg<r32> land;
	b8 auto_rotate;
	b8 enabled;
	Walker(r32 = 0.0f);
	~Walker();
	void awake();
	b8 slide(Vec2*, const Vec3&);
	btCollisionWorld::ClosestRayResultCallback check_support(r32 = 0.0f);

	Vec3 base_pos() const;
	void absolute_pos(const Vec3&);
	Vec3 forward() const;
	r32 capsule_height() const;

	void update(const Update&);
};

}
