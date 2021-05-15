// ViDdiDispatchWmi 
 
int __fastcall ViDdiDispatchWmi(int a1, int a2)
{
  int v3; // r0
  int v4; // r4

  if ( *(_BYTE *)(*(_DWORD *)(a2 + 96) + 1) )
  {
    if ( *(_BYTE *)(*(_DWORD *)(a2 + 96) + 1) != 11 )
      goto LABEL_6;
    v3 = ViDdiDispatchWmiRegInfoEx();
  }
  else
  {
    v3 = ViDdiDispatchWmiQueryAllData(a1, a2);
  }
  v4 = v3;
  if ( v3 != -1073741637 )
  {
    *(_DWORD *)(a2 + 24) = v3;
    goto LABEL_8;
  }
LABEL_6:
  v4 = *(_DWORD *)(a2 + 24);
LABEL_8:
  IofCompleteRequest(a2, 0);
  return v4;
}
