# AWS

### Glossary

- IAM: Identity and Access Management, é um “usuário” de acesso a aws
- IAM identifiers: IAM uses a few different identifiers for users, user groups, roles, policies, and server certificates.
- IAM ARN: Most resources have a friendly name (for example, a user named `Bob` or a user group named `Developers`). However, the permissions policy language requires you to specify the resources by using the following *Amazon Resource Name (ARN)* format.
    
     `arn:`partition`:`service`:`region`:`account`:`resource`
    
    - `partition` identifies the partition for the resource . For standard AWS Regions, the partition is `aws`. If you have resources in other partitions, the partition is `aws-partitionname`. For example, the partition for resources in the China (Beijing) Region is `aws-cn`. You cannot [delegate access](https://docs.aws.amazon.com/IAM/latest/UserGuide/id_roles_compare-resource-policies.html#aboutdelegation-resourcepolicy) between accounts in different partitions.
        - `service` identifies the AWS product. IAM resources always uses `iam`.
        - `region` identifies the Region of the resource . For IAM resources, this is always kept blank.
        - `account` specifies the AWS account ID with no hyphens or the alias for the AWS account.
        - `resource` identifies the specific resource by name.
- Lambda function’s execution role: is an AWS Identity and Access Management (IAM) role that grants the function permission to access AWS services and resources