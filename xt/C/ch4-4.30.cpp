SqString *MaxSubstr(SqString s)
{
 SqString *sp;
 int index=0,length=0,length1,i=0,j,k;
 while(i<s.len)
 {
  j=i+1;
  while(j<s.len)
  {
   if(s.ch[i]==s.ch[j])/*找一子串，其序号为i,长度为length*/
   {
    length1=1;
    for(k=1;s.ch[i+k]=s.ch[j+k];k++)
     length1++;
    if(length1>length)/*将较大长度者赋给index与length*/
    {
     index=i;
     length=length1;
    }
    j+=length1;
   }
   else
    j++;
  }
  i++;/*继续扫描第i个字符之后的字符*/
 }
 sp=(SqString *)malloc(sizeof(SqString));
 sp->len=length;
 for(i=0;i<length;i++)
  sp->ch[i]=s.ch[index+i];
 return sp;
}
