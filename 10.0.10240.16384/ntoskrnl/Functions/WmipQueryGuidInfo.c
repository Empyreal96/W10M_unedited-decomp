// WmipQueryGuidInfo 
 
int __fastcall WmipQueryGuidInfo(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r5
  int v7; // r6
  _DWORD *i; // r2
  int v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[0] = a4;
  v5 = ObReferenceObjectByHandle(*(_DWORD *)a1, 1, WmipGuidObjectType, 1, (int)v10, 0);
  if ( v5 >= 0 )
  {
    v6 = v10[0];
    v7 = *(_DWORD *)(v10[0] + 40);
    if ( v7 )
    {
      *(_BYTE *)(a1 + 8) = 0;
      KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
      for ( i = *(_DWORD **)(v7 + 32); i != (_DWORD *)(v7 + 32); i = (_DWORD *)*i )
      {
        if ( (i[2] & 4) != 0 )
        {
          *(_BYTE *)(a1 + 8) = 1;
          break;
        }
      }
      KeReleaseMutex((int)&WmipSMMutex);
    }
    else
    {
      v5 = -1073741055;
    }
    ObfDereferenceObject(v6);
  }
  return v5;
}
