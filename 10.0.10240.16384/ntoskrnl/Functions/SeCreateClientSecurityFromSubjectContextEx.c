// SeCreateClientSecurityFromSubjectContextEx 
 
int __fastcall SeCreateClientSecurityFromSubjectContextEx(int *a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7; // r9
  int v8; // r10
  int v9; // r6
  int v10; // r8
  int v11; // r5
  char v13[4]; // [sp+20h] [bp-28h] BYREF
  int v14; // [sp+24h] [bp-24h]
  int v15; // [sp+28h] [bp-20h]

  v5 = *a1;
  v7 = 0;
  v14 = a3;
  v15 = a2;
  v8 = 0;
  v13[0] = 0;
  if ( !v5 )
    v5 = a1[2];
  ObfReferenceObjectWithTag(v5);
  if ( *a1 )
  {
    v9 = *(_DWORD *)(a1[2] + 640);
    v10 = 2;
    RtlSidDominatesForTrust(v9, *(_DWORD *)(*a1 + 640), v13);
    if ( !v13[0] )
    {
      v8 = 1;
      v7 = v9;
    }
  }
  else
  {
    v10 = 1;
  }
  v11 = SepCreateClientSecurityEx(v5, v15, v14, v10, 0, a1[1], 1, 0, v8, v7, a4);
  if ( v11 < 0 || !*(_BYTE *)(a4 + 8) )
    ObfDereferenceObjectWithTag(v5);
  return v11;
}
