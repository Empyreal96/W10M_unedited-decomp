// MiWaitForVadDeletion 
 
int __fastcall MiWaitForVadDeletion(int result)
{
  int v1; // r5
  int v2; // r4
  _DWORD v3[2]; // [sp+0h] [bp-20h] BYREF
  char v4[4]; // [sp+8h] [bp-18h] BYREF
  int v5; // [sp+Ch] [bp-14h]
  int v6[4]; // [sp+10h] [bp-10h] BYREF

  v1 = result;
  if ( *(_DWORD *)(result + 8) != -1 )
  {
    v2 = __mrc(15, 0, 13, 0, 3);
    v3[1] = 1;
    v4[0] = 7;
    v4[1] = 1;
    v4[2] = 4;
    v5 = 0;
    v6[1] = (int)v6;
    v6[0] = (int)v6;
    MiInsertVadEvent(result, v3, 1);
    MiUnlockVad(v2 & 0xFFFFFFC0, v1);
    KeWaitForGate((int)v4, 18);
    result = MiLockVad(v2 & 0xFFFFFFC0, v1);
  }
  return result;
}
