// PopProcessWakeSourceWork 
 
int __fastcall PopProcessWakeSourceWork(int a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v3; // kr00_8
  _DWORD *v4; // r9
  _DWORD *v5; // r8
  int v6; // r5
  unsigned int v7; // r2
  _DWORD *v8; // r7
  int v9; // r1
  _DWORD *v10; // r6
  int v11; // r3
  unsigned int v12; // r3
  int v13; // r4
  int v14; // r9
  unsigned int v15; // r3
  int v16; // r5
  _BYTE *v17; // r4
  int v18; // r0
  int result; // r0
  unsigned int v21; // [sp+4h] [bp-2Ch]
  int v22; // [sp+8h] [bp-28h]

  v3 = *(_QWORD *)(a1 + 8);
  v4 = a3;
  v5 = 0;
  if ( (_DWORD)v3 )
    v6 = *(_DWORD *)(*(_DWORD *)(v3 + 176) + 20);
  else
    v6 = 0;
  v7 = *(_DWORD *)(v6 + 76);
  v8 = *(_DWORD **)(HIDWORD(v3) + 12);
  v21 = v7;
  if ( v8 != (_DWORD *)(HIDWORD(v3) + 12) )
  {
    v9 = IopRootDeviceNode;
    v22 = IopRootDeviceNode;
    do
    {
      v10 = v8;
      v11 = v8[2];
      v8 = (_DWORD *)*v8;
      if ( !v11 )
      {
        v12 = v10[9];
        if ( v12 <= v7 )
        {
          if ( v12 < v7 )
          {
            v13 = *(_DWORD *)(v6 + 8);
            if ( v13 == v9 )
              v13 = 0;
            if ( v13 )
            {
              v14 = *((unsigned __int16 *)v10 + 6);
              while ( 1 )
              {
                v15 = *(unsigned __int16 *)(v13 + 20);
                if ( v15 == v14 )
                {
                  if ( !wcsncmp(*(_WORD **)(v13 + 24), (unsigned __int16 *)v10[4], v15 >> 1) )
                  {
                    v5 = v10;
                    goto LABEL_26;
                  }
                  v9 = v22;
                }
                v13 = *(_DWORD *)(v13 + 8);
                if ( v13 == v9 )
                  v13 = 0;
                if ( !v13 )
                  goto LABEL_21;
              }
            }
          }
        }
        else
        {
          if ( PopWakeSourceIsParent(v6, v10 + 3) )
          {
            v16 = -1073741823;
            v4 = a3;
            goto LABEL_31;
          }
          v9 = v22;
LABEL_21:
          v7 = v21;
        }
      }
    }
    while ( v8 != (_DWORD *)(HIDWORD(v3) + 12) );
LABEL_26:
    v4 = a3;
  }
  v17 = PopNewWakeSource(0);
  if ( v17 )
  {
    *((_DWORD *)v17 + 9) = v21;
    v18 = ExAllocatePoolWithTag(1, *(unsigned __int16 *)(v6 + 20), 544040269);
    *((_DWORD *)v17 + 4) = v18;
    if ( v18 )
    {
      *((_WORD *)v17 + 7) = *(_WORD *)(v6 + 20);
      RtlCopyUnicodeString((unsigned __int16 *)v17 + 6, (unsigned __int16 *)(v6 + 20));
      PopWakeSourceGetDeviceProperty(v17 + 20, 9, v3);
      PopWakeSourceGetDeviceProperty(v17 + 28, 0, v3);
      v16 = 0;
      goto LABEL_34;
    }
    v16 = -1073741670;
    PopFreeWakeSource(v17);
LABEL_31:
    v17 = 0;
  }
  else
  {
    v16 = -1073741670;
  }
  v5 = 0;
LABEL_34:
  *v4 = v5;
  result = v16;
  *a2 = v17;
  return result;
}
