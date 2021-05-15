// WmipGenerateBinaryMofNotification 
 
int __fastcall WmipGenerateBinaryMofNotification(int result, _DWORD *a2)
{
  _DWORD *v2; // r7
  int v3; // r8
  int v4; // r3
  unsigned int v5; // r9
  unsigned int v6; // r10
  int v7; // r3
  int v8; // r4
  int v9; // r5
  unsigned int v10; // r9
  _WORD *v11; // r4
  int v12; // r3

  v2 = (_DWORD *)result;
  if ( *(_DWORD *)(result + 36) )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = v2[2];
      if ( (v4 & 2) != 0 )
        break;
      if ( (v4 & 1) != 0 )
      {
        v5 = 2 * (wcslen((unsigned __int16 *)(v2[12] + 4)) + 7);
        result = ExAllocatePoolWithTag(1, v5 + 74, 1885957463);
        v6 = result;
        if ( result )
        {
          *(_DWORD *)result = v5 + 74;
          *(_DWORD *)(result + 4) = 3;
          *(_DWORD *)(result + 44) = 10;
          *(_QWORD *)(result + 8) = 1i64;
          v7 = a2[1];
          v8 = a2[2];
          v9 = a2[3];
          *(_DWORD *)(result + 24) = *a2;
          *(_DWORD *)(result + 28) = v7;
          *(_DWORD *)(result + 32) = v8;
          *(_DWORD *)(result + 36) = v9;
          KeQuerySystemTime((_DWORD *)(result + 16));
          *(_DWORD *)(v6 + 48) = 64;
          *(_DWORD *)(v6 + 56) = 72;
          *(_DWORD *)(v6 + 60) = v5 + 2;
          *(_WORD *)(v6 + 64) = 0;
          v10 = v5 - 2;
          v11 = (_WORD *)(v6 + *(_DWORD *)(v6 + 56));
          *v11 = 0;
          v12 = v2[2];
          if ( (v12 & 2) != 0 )
          {
            v11[1] = v10;
            RtlStringCbCopyW((int)(v11 + 2), v10);
          }
          else if ( (v12 & 1) != 0 )
          {
            RtlStringCbPrintfExW(v11 + 2, v10, 0, 0, 512, L"%ws%d", v2[12] + 4, *(_DWORD *)v2[12] + v3);
            v11[1] = v10;
          }
          WmipProcessEvent((unsigned int *)v6, 1, 0);
          result = ExFreePoolWithTag(v6);
        }
        if ( (unsigned int)++v3 < v2[9] )
          continue;
      }
      return result;
    }
    result = sub_81A2F8();
  }
  return result;
}
