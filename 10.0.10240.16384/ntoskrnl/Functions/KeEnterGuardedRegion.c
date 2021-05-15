// KeEnterGuardedRegion 
 
void KeEnterGuardedRegion()
{
  unsigned int v0; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 310);
}
