// NtImpersonateThread 
 
int __fastcall NtImpersonateThread(int a1, int a2, int a3, int a4)
{
  char v6; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r4
  int v10; // r0
  int v11; // r0
  int v13; // [sp+Ch] [bp-74h] BYREF
  _DWORD *v14; // [sp+10h] [bp-70h] BYREF
  _DWORD v15[4]; // [sp+18h] [bp-68h] BYREF
  int _28[28]; // [sp+28h] [bp-58h] BYREF

  _28[26] = a3;
  _28[27] = a4;
  _28[25] = a2;
  _28[24] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 && (a3 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v7 = *(_DWORD *)(a3 + 4);
  v8 = *(_DWORD *)(a3 + 8);
  v15[0] = *(_DWORD *)a3;
  v15[1] = v7;
  v15[2] = v8;
  v9 = ObReferenceObjectByHandle(a2, 512, PsThreadType, v6, (int)&v13, 0);
  if ( v9 >= 0 )
  {
    v9 = ObReferenceObjectByHandle(a1, 256, PsThreadType, v6, (int)&v14, 0);
    v10 = v13;
    if ( v9 >= 0 )
    {
      v11 = SeCreateClientSecurity(v13, (int)v15, 0, (int)_28);
      v9 = v11;
      if ( v11 >= 0 )
      {
        v9 = SeImpersonateClientEx((int)_28, v14);
        ObfDereferenceObject(_28[3]);
      }
      ObfDereferenceObject((int)v14);
      v10 = v13;
    }
    ObfDereferenceObject(v10);
  }
  return v9;
}
