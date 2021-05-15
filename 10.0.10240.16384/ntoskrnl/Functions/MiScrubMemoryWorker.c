// MiScrubMemoryWorker 
 
int __fastcall MiScrubMemoryWorker(int *a1)
{
  int v2; // r0
  int *v3; // r3
  unsigned int *v4; // r5
  int v5; // r6
  unsigned int *v6; // r1
  int v7; // r3
  unsigned int v8; // r4
  int result; // r0
  unsigned int v10; // r2
  unsigned int v11; // r2
  _DWORD v12[12]; // [sp+0h] [bp-30h] BYREF

  v2 = *a1;
  v3 = &a1[-6 * v2];
  v4 = (unsigned int *)(v3 - 7);
  v5 = MiInitializeScrubPacket(v2, *(v3 - 2), v12);
  if ( v5 >= 0 )
  {
    MiScrubNode(v12);
    MiReleaseScrubPacket((int)v12);
  }
  a1[1] = v5;
  v6 = v4 + 6;
  v7 = v12[6];
  do
  {
    v8 = __ldrex(v6);
    result = v8 + v7;
  }
  while ( __strex(v8 + v7, v6) );
  __dmb(0xBu);
  do
  {
    v10 = __ldrex(v4);
    v11 = v10 - 1;
  }
  while ( __strex(v11, v4) );
  if ( !v11 )
    result = KeSignalGate((int)(v4 + 1), 1);
  return result;
}
