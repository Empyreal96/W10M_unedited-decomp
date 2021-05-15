// NtIsProcessInJob 
 
int __fastcall NtIsProcessInJob(int a1, int a2)
{
  unsigned int v4; // r3
  int v5; // r9
  int v6; // r2
  int v7; // r5
  int v8; // r4
  int v9; // r1
  int v10; // r1
  int v12; // [sp+10h] [bp-28h] BYREF
  int v13[9]; // [sp+14h] [bp-24h] BYREF

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(char *)(v4 + 346);
  v6 = 0;
  if ( a1 == -1 )
  {
    v8 = *(_DWORD *)(v4 + 116);
    v12 = v8;
  }
  else
  {
    v7 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v5, 1649046352, &v12, 0);
    if ( v7 < 0 )
      return v7;
    v8 = v12;
    v6 = 0;
  }
  if ( !a2 )
  {
    v9 = *(_DWORD *)(v8 + 288);
    __dmb(0xBu);
    v8 = v12;
    goto LABEL_6;
  }
  v7 = ObReferenceObjectByHandle(a2, 4, PsJobType, v5, v13, 0);
  v9 = v13[0];
  if ( v7 >= 0 )
  {
LABEL_6:
    v7 = PspIsProcessInJob(v8, v9, v6, v4);
    if ( a2 )
      ObfDereferenceObject(v10);
  }
  if ( a1 != -1 )
    ObfDereferenceObjectWithTag(v8);
  return v7;
}
