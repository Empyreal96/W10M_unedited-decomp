// DbgkpLkmdSnapPendingIrps 
 
int __fastcall DbgkpLkmdSnapPendingIrps(int a1, int a2, int *a3)
{
  int *v3; // r8
  int *v4; // r4
  int result; // r0
  int v8; // r6
  _WORD *v9; // r1
  _WORD *v10; // r1
  _WORD *v11; // r1

  v3 = (int *)(a2 + 908);
  v4 = *(int **)(a2 + 908);
  if ( v4 == (int *)(a2 + 908) )
  {
    result = 0;
    a3[1] |= 8u;
  }
  else
  {
    while ( 1 )
    {
      ++a3[2];
      result = DbgkpLkmdSnapData(a1);
      if ( result < 0 )
        break;
      if ( *((_WORD *)v4 - 8) != 6 )
      {
        result = -1073741503;
        break;
      }
      result = DbgkpLkmdSnapData(a1);
      if ( result < 0 )
        break;
      ++a3[3];
      if ( *((char *)v4 + 19) <= *((char *)v4 + 18) )
      {
        v8 = v4[20];
        result = DbgkpLkmdSnapData(a1);
        if ( result != -1073741819 )
        {
          if ( result == -1073741670 )
            break;
          v9 = *(_WORD **)(v8 + 28);
          if ( v9 )
            DbgkpLkmdSnapObject(a1, v9, 5);
          v10 = *(_WORD **)(v8 + 24);
          if ( v10 )
          {
            DbgkpLkmdSnapObject(a1, v10, 3);
            v11 = *(_WORD **)(*(_DWORD *)(v8 + 24) + 8);
            if ( v11 )
              DbgkpLkmdSnapObject(a1, v11, 4);
          }
        }
      }
      v4 = (int *)*v4;
      if ( v4 == v3 )
      {
        result = 0;
        a3[1] |= 8u;
        break;
      }
    }
    *a3 = result;
  }
  return result;
}
