// AslpFileGetClrVersion 
 
int __fastcall AslpFileGetClrVersion(_BYTE *a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r5
  int v7; // r0
  int v8; // r4
  int v9; // r4
  int v10; // r2
  int v11; // r0
  _DWORD *v12; // r0
  int v13; // r4
  _DWORD v15[9]; // [sp+Ch] [bp-24h] BYREF

  v15[1] = a3;
  v15[2] = a4;
  v15[0] = 0;
  v6 = 0;
  *a1 = 0;
  v7 = AslpFileGetImageNtHeader(v15, a2);
  v8 = v7;
  if ( v7 >= 0 )
  {
    v9 = v15[0];
    v10 = *(unsigned __int16 *)(v15[0] + 24);
    if ( v10 == 267 )
    {
      v6 = (_DWORD *)(v15[0] + 232);
    }
    else if ( v10 == 523 )
    {
      v6 = (_DWORD *)(v15[0] + 248);
    }
    if ( v6 && *v6 && v6[1] >= 0x48u )
    {
      v11 = AslpImageRvaToVa(v15[0], a2 + 520);
      if ( v11 )
      {
        if ( *(_WORD *)(v11 + 4) == 2 )
        {
          v12 = (_DWORD *)AslpImageRvaToVa(v9, a2 + 520);
          if ( v12 )
          {
            if ( *v12 == 1112167234 )
            {
              v13 = v12[3];
              if ( (unsigned int)(v13 - 1) > 0xFE )
              {
                v8 = -1073741701;
                AslLogCallPrintf(1, (int)"AslpFileGetClrVersion", 3818, "CLR version string null or too long");
              }
              else
              {
                memmove((int)a1, (int)(v12 + 4), v12[3]);
                a1[v13] = 0;
                v8 = 0;
              }
            }
            else
            {
              v8 = -1073741637;
              AslLogCallPrintf(1, (int)"AslpFileGetClrVersion", 3806, "Invalid COR20 Metadata signature encountered");
            }
          }
          else
          {
            v8 = -1073741701;
            AslLogCallPrintf(
              1,
              (int)"AslpFileGetClrVersion",
              3796,
              "Invalid COR20 Metadata virtual address encountered");
          }
        }
        else
        {
          v8 = -1073741637;
        }
      }
      else
      {
        v8 = -1073741701;
        AslLogCallPrintf(1, (int)"AslpFileGetClrVersion", 3776, "Invalid COM Descriptor virtual address encountered");
      }
    }
    else
    {
      v8 = -1073741701;
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslpFileGetClrVersion", 3747, "AslpFileGetImageNtHeader failed [%x]", v7);
  }
  return v8;
}
