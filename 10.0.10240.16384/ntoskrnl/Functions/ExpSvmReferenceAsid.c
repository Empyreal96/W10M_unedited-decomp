// ExpSvmReferenceAsid 
 
int __fastcall ExpSvmReferenceAsid(unsigned int a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4
  int v4; // r3
  unsigned int v6; // r1
  unsigned int v7; // r3
  char v8[24]; // [sp+8h] [bp-18h] BYREF

  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_619EF0, (unsigned int)v8);
  v2 = (unsigned int *)(dword_619EEC + 8 * a1);
  if ( a1 >= dword_619EE4 )
  {
    v6 = 0;
LABEL_7:
    if ( a1 >= dword_619EE4 )
      v7 = 0;
    else
      v7 = *v2;
    KeBugCheck2(344, a1, dword_619EE4, v7, v6, 0);
  }
  v3 = *v2;
  if ( !*v2 || (v4 = v2[1], v4 < 0) )
  {
    v6 = v2[1];
    goto LABEL_7;
  }
  v2[1] = v4 + 1;
  KeReleaseInStackQueuedSpinLock((int)v8);
  return *(_DWORD *)(v3 + 744);
}
