// PfpServiceMainThreadBoostPrep 
 
int __fastcall PfpServiceMainThreadBoostPrep(int a1, int *a2, int a3, int a4)
{
  int v5; // r0
  int v7; // r4
  int v8; // r5
  int v9; // r0
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = *(_DWORD *)(a1 + 44);
  v11[0] = 0;
  if ( !v5 )
    return -2147483614;
  v7 = PsLookupThreadByThreadId(v5, v11);
  v8 = v11[0];
  if ( v7 >= 0 )
  {
    if ( *(_QWORD *)(v11[0] + 832) == *(_QWORD *)(a1 + 48) )
    {
      v9 = ExAllocatePoolWithTag(512, 104, 1146119760);
      if ( v9 )
      {
        *a2 = v8;
        a2[1] = v9;
        return 0;
      }
      v7 = -1073741670;
    }
    else
    {
      v7 = -1073741735;
    }
  }
  if ( v8 )
    ObDereferenceObjectDeferDelete(v8);
  return v7;
}
