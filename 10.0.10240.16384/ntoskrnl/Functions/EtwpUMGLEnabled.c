// EtwpUMGLEnabled 
 
int __fastcall EtwpUMGLEnabled(int a1)
{
  int v2; // r5
  int v3; // r5
  unsigned int *v4; // r0
  unsigned int v5; // r4
  unsigned int v6; // r1
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  _BYTE v11[48]; // [sp+8h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 320);
  if ( !v2 )
    return 0;
  v4 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v5 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  do
    v6 = __ldrex(v4);
  while ( v6 == v5 && __strex(v5 + 2, v4) );
  __dmb(0xBu);
  if ( v6 != v5 && !ExfAcquireRundownProtection(v4) )
    return 0;
  KiStackAttachProcess(a1, 0, (int)v11);
  v3 = *(_BYTE *)(v2 + 576) & 1;
  KiUnstackDetachProcess((unsigned int)v11, 0);
  v7 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v8 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v9 = __ldrex(v7);
  while ( v9 == v8 && __strex(v8 - 2, v7) );
  if ( v9 != v8 )
    ExfReleaseRundownProtection((unsigned __int8 *)v7);
  return v3;
}
