// sub_51C360 
 
void __fastcall sub_51C360(int a1, int a2, int a3)
{
  _QWORD *v3; // r5
  int v4; // r9
  unsigned __int8 v5; // r10
  _QWORD *v6; // r4
  int v7; // r3
  int *v8; // r0

  if ( !a3 )
  {
    if ( *v3 > *(_QWORD *)(a2 - 80) )
    {
      v6 = v3;
      do
      {
        v7 = *((_DWORD *)v6 + 59);
        if ( v7 )
          v8 = (int *)(v7 + 228);
        else
          v8 = (int *)(v4 + 1976);
        *((_BYTE *)v6 + 92) &= 0xFEu;
        RtlRbRemoveNode(v8, (_DWORD *)v6 + 20);
        v6 = (_QWORD *)*((_DWORD *)v6 + 59);
      }
      while ( v6 && (*((_BYTE *)v6 + 92) & v5) != 0 && !*((_DWORD *)v6 + 57) && !*((_WORD *)v6 + 47) );
      KiInsertSchedulingGroupQueue(v4, (int)v3, 0);
    }
    JUMPOUT(0x446E6A);
  }
  JUMPOUT(0x446EE0);
}
