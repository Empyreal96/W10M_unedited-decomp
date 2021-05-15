// ObpInitStackTrace 
 
int ObpInitStackTrace()
{
  _BYTE *v0; // r0

  ObpObjectBuckets = 401;
  ObpMaxStacks = 16381;
  ObpTraceDepth = 16;
  ObpStackBuckets = 16;
  ObpStacksPerBucket = 1024;
  ObpStackTraceLock = 0;
  dword_61FE28 = (int)ObpPushStackInfoQueue;
  dword_61FE2C = 0;
  ObpPushStackInfoWorkItem = 0;
  ObpPushStackInfoList = 0;
  memset(&ObpRegTracePoolTags, 0, 64);
  v0 = memset(ObpRuntimeTracePoolTags, 0, sizeof(ObpRuntimeTracePoolTags));
  ObpNumTracedObjects = 0;
  ObpStackSequence = 0;
  if ( !ObpTraceProcessNameBuffer )
    JUMPOUT(0x96FAEE);
  return sub_96FAC0(v0);
}
