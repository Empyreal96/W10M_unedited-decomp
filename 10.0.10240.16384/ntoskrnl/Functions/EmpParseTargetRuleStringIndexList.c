// EmpParseTargetRuleStringIndexList 
 
int __fastcall EmpParseTargetRuleStringIndexList(int a1, char *a2, unsigned int a3, int a4, int a5, unsigned int a6, int *a7)
{
  unsigned int v8; // r7
  unsigned int v9; // r8
  unsigned int v10; // lr
  int v11; // r2
  int v12; // r5
  int v13; // r6
  unsigned int v14; // r9
  int result; // r0
  int v16; // r3
  unsigned int v17; // r10
  int v18; // r9
  int v19; // r0
  char *v20; // r8
  int v21; // r1
  _DWORD *v22; // r10
  unsigned int v23; // [sp+8h] [bp-40h]
  unsigned int v24; // [sp+Ch] [bp-3Ch]
  unsigned int v25; // [sp+10h] [bp-38h]
  int v26; // [sp+14h] [bp-34h] BYREF
  int v27; // [sp+18h] [bp-30h]
  int v28; // [sp+1Ch] [bp-2Ch]
  _DWORD *v29; // [sp+20h] [bp-28h]
  int v30; // [sp+24h] [bp-24h]

  v25 = a3;
  v8 = 0;
  v9 = a4;
  v28 = a4;
  v23 = 0;
  v24 = 0;
  v10 = a3;
  v11 = *a7;
  v26 = 0;
  v27 = v11;
  v12 = 0;
  v13 = 0;
  v30 = a1;
  v14 = 0;
  if ( !a5 )
    return sub_96BE3C();
  v29 = (_DWORD *)(a5 + 4 * v11);
  while ( !v12 )
  {
    if ( v13 == 1 )
    {
      if ( *a2 == 125 )
        goto LABEL_37;
      if ( v8 > v10 )
        return 0;
      if ( v14 > v9 )
        return 0;
      v17 = v11 + v14 + v8;
      if ( v17 >= a6 )
        return 0;
      v18 = (int)a2;
      do
      {
        if ( strchr(".}", *a2) )
          break;
        ++a2;
      }
      while ( a2 );
      if ( &a2[-v18] == (char *)-1 )
      {
        v14 = v23;
        v8 = v24;
        v11 = v27;
        v10 = v25;
        v12 = 1;
      }
      else
      {
        v19 = ExAllocatePoolWithTag(1, (int)&a2[-v18 + 1], 1953058117);
        v20 = (char *)v19;
        if ( v19 && sub_43E028(v19, (unsigned int)&a2[-v18 + 1]) >= 0 )
        {
          if ( (unsigned int)&a2[-v18] > 0x7FFFFFFE )
          {
            *v20 = 0;
          }
          else if ( sub_455C10(v20, v21, (int)&a2[-v18], v18, (int)&a2[-v18]) >= 0 )
          {
            v8 = v24;
            if ( v24 < v25 )
            {
              v14 = v23;
              if ( EmpInfParseGetStringIndexFromName(v30, v20, &v26) < 0 )
                goto LABEL_38;
              v22 = v29;
              v8 = ++v24;
              *v29 = v26;
              v29 = v22 + 1;
LABEL_24:
              v13 = 2;
            }
            else
            {
              v14 = v23;
              if ( RtlCharToInteger(v20, 0x10u, &v26) >= 0 )
              {
                v14 = ++v23;
                *(_DWORD *)(a5 + 4 * v17) = v26;
                goto LABEL_24;
              }
LABEL_38:
              v12 = 1;
            }
            ExFreePoolWithTag((unsigned int)v20);
            goto LABEL_26;
          }
        }
        v14 = v23;
        v8 = v24;
        v12 = 1;
LABEL_26:
        v11 = v27;
        v9 = v28;
        v10 = v25;
      }
    }
    else if ( v13 == 2 )
    {
      v16 = *a2;
      if ( v16 == 46 )
        goto LABEL_8;
      if ( v16 == 125 )
      {
LABEL_37:
        ++a2;
        v13 = 3;
      }
      else
      {
LABEL_31:
        v12 = 1;
      }
    }
    else
    {
      if ( v13 )
      {
        if ( !*a2 && v8 == v10 && v14 == v9 )
        {
          result = 1;
          *a7 = v11 + v14 + v8;
          return result;
        }
        goto LABEL_31;
      }
      if ( *a2 != 123 )
        goto LABEL_31;
LABEL_8:
      ++a2;
      v13 = 1;
    }
  }
  return 0;
}
