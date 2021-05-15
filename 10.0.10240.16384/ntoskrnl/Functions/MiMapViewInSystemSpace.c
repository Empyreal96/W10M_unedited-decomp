// MiMapViewInSystemSpace 
 
int __fastcall MiMapViewInSystemSpace(int a1, int a2, unsigned int *a3, unsigned int *a4, __int64 *a5, int a6)
{
  int v8; // r4
  unsigned int v9; // r5
  _DWORD *v10; // r9
  unsigned int v11; // r2
  __int64 v12; // kr00_8
  __int64 v13; // kr08_8
  unsigned int v14; // r1
  int v15; // r2
  int v16; // r7
  unsigned int v17; // r0

  if ( (a6 & 0xFFFFFFFE) != 0 )
    return -1073741580;
  v9 = 0;
  v10 = (_DWORD *)MiSectionControlArea(a1);
  MiCheckPurgeAndUpMapCount(v10);
  v11 = *a4;
  if ( *a4 )
  {
    if ( v11 + (unsigned __int64)*(unsigned __int16 *)a5 < *(unsigned __int16 *)a5 )
      goto LABEL_15;
    *a4 = *(unsigned __int16 *)a5 + v11;
    *(_WORD *)a5 = 0;
    v13 = *(_QWORD *)(a1 + 24) - *a5;
    if ( HIDWORD(v13) > 1 || HIDWORD(v13) || *a4 > (unsigned int)v13 )
      goto LABEL_15;
  }
  else
  {
    *(_WORD *)a5 = 0;
    v12 = *(_QWORD *)(a1 + 24) - *a5;
    if ( HIDWORD(v12) )
      goto LABEL_15;
    *a4 = v12;
  }
  v14 = ((unsigned __int16)*a4 != 0) + HIWORD(*a4);
  if ( v14 < 0x10000 )
  {
    v15 = a1;
    v16 = a2;
    v17 = MiInsertInSystemSpace(a2, v14, v15, a5, a6);
    v9 = v17;
    if ( v17 )
    {
      v8 = MiAddMappedPtes(((v17 >> 10) & 0x3FFFFC) - 0x40000000, ((*a4 & 0xFFF) != 0) + (*a4 >> 12), v10, a5, -1);
      if ( v8 >= 0 )
      {
        v8 = 0;
        *a3 = v9;
        return v8;
      }
    }
    else
    {
      v8 = -1073741801;
    }
    goto LABEL_16;
  }
LABEL_15:
  v16 = a2;
  v8 = -1073741793;
LABEL_16:
  MiDereferenceControlArea(v10);
  if ( v9 )
    MiRemoveFromSystemSpace(v16, v9, 0);
  return v8;
}
