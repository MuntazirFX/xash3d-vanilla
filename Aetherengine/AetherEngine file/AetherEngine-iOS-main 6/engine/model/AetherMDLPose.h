/* AetherMDLPose.h — GoldSrc MDL skeletal pose sampling and CPU skinning.
 * AetherEngine-iOS · Clean-room.
 */
#ifndef AETHER_MDL_POSE_H
#define AETHER_MDL_POSE_H

#include "AetherMDL.h"
#include "AetherMDLGeometry.h"
#include "AetherMDLSequence.h"
#include "../core/AetherMath.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AETHER_MDL_POSE_MAX_BONES 128

typedef struct aether_mdl_bone_pose {
    f32 position[3];
    f32 quaternion[4]; /* x, y, z, w */
    aether_mat4_t matrix; /* model-space bone transform */
} aether_mdl_bone_pose_t;

typedef struct aether_mdl_pose {
    aether_mdl_bone_pose_t *bones;
    u32 bone_count;
    i32 sequence;
    f32 frame;
    f32 blend[2];
} aether_mdl_pose_t;

void aether_mdl_pose_init(aether_mdl_pose_t *pose);
void aether_mdl_pose_free(aether_mdl_pose_t *pose);

aether_result_t aether_mdl_pose_build(const aether_mdl_t *mdl,
                                       i32 sequence,
                                       f32 frame,
                                       f32 blend0,
                                       f32 blend1,
                                       aether_mdl_pose_t *out);

const aether_mdl_bone_pose_t *aether_mdl_pose_bone_at(const aether_mdl_pose_t *pose,
                                                       u32 index);

/* CPU skinning is used as the compatibility path for the current Metal renderer.
   It transforms the expanded MDL triangle list using its source bone index. */
aether_result_t aether_mdl_pose_skin_mesh(const aether_model_mesh_t *mesh,
                                          const aether_mdl_pose_t *pose,
                                          f32 *out_positions,
                                          f32 *out_normals,
                                          u32 max_vertices);

void aether_mdl_pose_dump(const aether_mdl_pose_t *pose);

#ifdef __cplusplus
}
#endif
#endif /* AETHER_MDL_POSE_H */
