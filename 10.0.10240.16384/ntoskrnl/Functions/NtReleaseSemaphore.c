// NtReleaseSemaphore 
 
int __fastcall NtReleaseSemaphore(int a1, int a2, int *a3, int a4)
{
  int *v4; // r5
  int v6; // r3
  int v7; // r8
  int v8; // r4
  int v9; // r9
  int v10; // r6
  int _10[16]; // [sp+10h] [bp-28h] BYREF

  _10[15] = a4;
  v4 = a3;
  _10[14] = (int)a3;
  _10[13] = a2;
  _10[12] = a1;
  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = *(char *)((v6 & 0xFFFFFFC0) + 0x15A);
  if ( a3 && *(_BYTE *)((v6 & 0xFFFFFFC0) + 0x15A) )
  {
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      a3 = (int *)MmUserProbeAddress;
    *a3 = *a3;
  }
  if ( a2 <= 0 )
    return -1073741811;
  v8 = ObReferenceObjectByHandle(a1, 2, ExSemaphoreObjectType, v7, _10);
  _10[1] = v8;
  if ( v8 >= 0 )
  {
    v9 = _10[0];
    v10 = KeReleaseSemaphore(_10[0], 1, a2);
    ObfDereferenceObject(v9);
    if ( v4 )
      *v4 = v10;
  }
  return v8;
}
